<?php

/**
 * @file
 * Definition of views_handler_field_domain_link_edit.
 */

/**
 * Field handler to present a link to delete a domain.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_domain_link_delete extends views_handler_field_domain_link {
  function render_link($data, $values) {

    if ($data && user_access('administer domains')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = !empty($this->options['text']) ? $this->options['text'] : t('Delete');

      $this->options['alter']['path'] = "domain/$data/delete";
      $this->options['alter']['query'] = backdrop_get_destination();

      return $text;
    }
  }
}
