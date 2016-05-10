<?php

/**
 * @file
 * Provide views data and handlers for user.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function domain_views_data() {
  // ----------------------------------------------------------------
  // domain table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['domain']['table']['group']  = t('Domain');

  $data['domain']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Domain'),
    'help' => t('Users who have created accounts on your site.'),
//    'access query tag' => 'user_access',
  );
  $data['domain']['table']['entity type'] = 'domain';

  // id
  $data['domain']['id'] = array(
    'title' => t('ID'),
    'help' => t('The domain ID.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // id
  $data['domain']['id_current'] = array(
    'real field' => 'id',
    'title' => t('Current'),
    'help' => t('Filter the view to the current domain.'),
    'filter' => array(
      'handler' => 'views_handler_filter_domain_current',
      'type' => 'yes-no',
    ),
  );

  // title
  $data['domain']['title'] = array(
    'title' => t('Title'), // The item it appears as on the UI,
    'help' => t('The domain title.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_domain',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'title' => t('Title (raw)'),
      'help' => t('The domain title. This filter does not check if the domain exists and allows partial matching. Does not utilize autocomplete.')
    ),
  );

  // name
  $data['domain']['name'] = array(
    'title' => t('Name'), // The item it appears as on the UI,
    'help' => t('The unique domain name.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_domain',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'title' => t('Name (raw)'),
      'help' => t('The unique domain name. This filter does not check if the domain exists and allows partial matching. Does not utilize autocomplete.')
    ),
  );

  // created field
  $data['domain']['created'] = array(
    'title' => t('Created date'), // The item it appears as on the UI,
    'help' => t('The date the domain was created.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['domain']['created_fulldate'] = array(
    'title' => t('Created date'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['domain']['created_year_month'] = array(
    'title' => t('Created year + month'),
    'help' => t('Date in the form of YYYYMM.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['domain']['timestamp_year']['moved to'] = array('domain', 'created_year');
  $data['domain']['created_year'] = array(
    'title' => t('Created year'),
    'help' => t('Date in the form of YYYY.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['domain']['created_month'] = array(
    'title' => t('Created month'),
    'help' => t('Date in the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['domain']['created_day'] = array(
    'title' => t('Created day'),
    'help' => t('Date in the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['domain']['created_week'] = array(
    'title' => t('Created week'),
    'help' => t('Date in the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  // Changed field
  $data['domain']['changed'] = array(
    'title' => t('Changed date'), // The item it appears as on the UI,
    'help' => t('The date the domain was changed.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['domain']['changed_fulldate'] = array(
    'title' => t('changed date'),
    'help' => t('Date in the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_fulldate',
    ),
  );

  $data['domain']['changed_year_month'] = array(
    'title' => t('changed year + month'),
    'help' => t('Date in the form of YYYYMM.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_year_month',
    ),
  );

  $data['domain']['timestamp_year']['moved to'] = array('domain', 'changed_year');
  $data['domain']['changed_year'] = array(
    'title' => t('changed year'),
    'help' => t('Date in the form of YYYY.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_year',
    ),
  );

  $data['domain']['changed_month'] = array(
    'title' => t('changed month'),
    'help' => t('Date in the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_month',
    ),
  );

  $data['domain']['changed_day'] = array(
    'title' => t('changed day'),
    'help' => t('Date in the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_day',
    ),
  );

  $data['domain']['changed_week'] = array(
    'title' => t('changed week'),
    'help' => t('Date in the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_changed_week',
    ),
  );

  // active status
  $data['domain']['status'] = array(
    'title' => t('Active'), // The item it appears as on the UI,
    'help' => t('Whether a domain is active or blocked.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'active-blocked' => array(t('Enabled'), t('Disabled')),
      ),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Active'),
      'type' => 'active-blocked',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['domain']['edit_link'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the domain.'),
      'handler' => 'views_handler_field_domain_link_edit',
    ),
  );

/*  $data['domain']['cancel_node'] = array(
    'field' => array(
      'title' => t('Cancel link'),
      'help' => t('Provide a simple link to cancel the user.'),
      'handler' => 'views_handler_field_user_link_cancel',
    ),
  );*/

/*  $data['domain']['bulk_form'] = array(
    'title' => t('Bulk operations'),
    'help' => t('Provides a checkbox on each row and a form for executing bulk actions on domains.'),
    'real field' => 'id',
    'field' => array(
      'handler' => 'views_handler_field_bulk_form',
      'click sortable' => FALSE,
    ),
  );*/

  return $data;
}

/**
 * Allow replacement of current user ID so we can cache these queries.
 */
function domain_views_query_substitutions($view) {
  return array('***CURRENT_DOMAIN_ID***' => domain_get_current_domain_id());
}
