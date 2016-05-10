<?php

/**
 * @file
 * Definition of views_handler_field_domain_link_edit.
 */

/**
 * Field handler to present a link to domain edit.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_domain_link_edit extends views_handler_field_domain_link {
  function render_link($data, $values) {

    if ($data && user_access('administer domains')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');

      $this->options['alter']['path'] = "domain/$data/edit";
      $this->options['alter']['query'] = backdrop_get_destination();

      return $text;
    }
  }
}
