<?php

/**
 * Implements hook_field_info().
 *
 * @todo: replace with default entity reference field?
 */
function domain_field_info() {
  return array(
    'domain' => array(
      'label' => t('Domain'),
      'description' => t('This field stores the domain id.'),
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '', // @todo!
      ),
      'default_widget' => 'domain_select',
      'default_formatter' => 'domain_title',
      'default_token_formatter' => 'list_default', // @todo!
    ),
  );
}

/**
 * Implements hook_options_list().
 */
function domain_options_list($field, $instance, $entity_type, $entity) {
  global $user;

  switch ($entity_type) {
    case 'node':
      if (!user_access('bypass node access')) {
        return _domains_get_assigned_domain_names($user);
      }
      break;

    case 'user':
      if (!user_access('domain assign any')) {
        return _domains_get_assigned_domain_names($user);
      }
      break;
  }

  return domain_get_domain_titles();
}

/**
 * Implements hook_field_is_empty().
 */
function domain_field_is_empty($item, $field) {
  return list_field_is_empty($item, $field);
}

/**
 * Implements hook_field_widget_form().
 *
 * @see options_field_widget_form()
 */
function domain_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $instance['widget']['type'] = 'options_' . substr($instance['widget']['type'], 7);
  $element = options_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);

  // Set current domain as default for empty but required fields.
  if ($element['#required'] && empty($element['#default_value']) && ($domain = domain_get_current_domain_id()) != DOMAIN_NO_DOMAIN) {
    $multiple = $field['cardinality'] > 1 || $field['cardinality'] == FIELD_CARDINALITY_UNLIMITED;
    $element['#default_value'] = ($multiple) ? array($domain) : $domain;
  }

  return $element;
}

/**
 * Implements hook_field_formatter_info().
 */
function domain_field_formatter_info() {
  return array(
    'domain_title' => array(
      'label' => t('Title'),
      'field types' => array('domain'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function domain_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $domains = domain_get_domain_titles();

  switch ($display['type']) {
    case 'domain_title':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => $domains[$item['value']]);
      }
      break;
  }

  return $element;
}


/**
 * Implements hook_field_schema().
 */
function domain_field_schema($field) {
  $schema = array();

  $schema['columns']['value'] = array(
    'description' => 'The primary identifier for a domain.',
    'type' => 'int',
    'unsigned' => TRUE,
    'not null' => TRUE,
  );

  return $schema;
}

/**
 * Implements hook_field_widget_info().
 */
function domain_field_widget_info() {
  return array(
    'domain_select' => array(
      'label' => t('Select list'),
      'field types' => array('domain'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
      ),
    ),
    'domain_buttons' => array(
      'label' => t('Check boxes/radio buttons'),
      'field types' => array('domain'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
      ),
    ),
  );
}
