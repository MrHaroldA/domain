<?php

/**
 * @file
 * Contains the basic 'domain' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a domain.
 * Definition terms:
 * - link_to_domain default: Should this field have the checkbox "link to domain" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_domain extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby
    if (!empty($this->options['link_to_domain'])) {
      $this->additional_fields['url'] = array('table' => 'domain', 'field' => 'url');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_domain'] = array('default' => isset($this->definition['link_to_domain default']) ? $this->definition['link_to_domain default'] : FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Provide link to domain option
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_domain'] = array(
      '#title' => t('Link this field to the domain url'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_domain']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the domain.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_domain']) && !empty($this->additional_fields['url'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = '//' . $this->get_value($values, 'url');
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
