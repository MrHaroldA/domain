<?php

/**
 * @file
 * Entity classes and controllers for Domain module.
 */

/**
 * Defines the domain entity class.
 */
class Domain extends Entity {

  /**
   * The domain ID.
   *
   * @var integer
   */
  public $id;

  /**
   * The domain title.
   *
   * @var string
   */
  public $title = '';

  /**
   * The unique domain name.
   *
   * @var string
   */
  public $name = '';

  /**
   * The domain's main url.
   *
   * @var string
   */
  public $url = '';

  /**
   * The optional custom theme.
   *
   * @var string
   */
  public $theme;

  /**
   * The timestamp when the domain was created.
   *
   * @var integer
   */
  public $created;

  /**
   * The timestamp when the domain was last changed.
   *
   * @var integer
   */
  public $changed;

  /**
   * The url aliases for this domain.
   *
   * @var integer
   */
  public $aliases = array();

  /**
   * Whether the domain is active (1) or blocked (0).
   *
   * @var integer
   */
  public $status = 1;

  /**
   * Implements EntityInterface::id().
   */
  public function id() {
    return isset($this->id) ? $this->id : NULL;
  }

  /**
   * Implements EntityInterface::entityType().
   */
  public function entityType() {
    return 'domain';
  }

  /**
   * Implements EntityInterface::label().
   */
  public function label() {
    return $this->name;
  }

  /**
   * Implements EntityInterface::uri().
   */
  public function uri() {
    return ($this->url) ? '//' . $this->url : NULL;
  }

  /**
   * Implements EntityInterface::save().
   */
  public function save() {

    // Save the domain.
    $return = parent::save();

    // Delete and insert all aliases. Big fat @todo!
    db_query("DELETE FROM {domain_alias} WHERE domain_id = :domain_id", array(':domain_id' => $this->id));
    foreach (array_filter($this->aliases) as $alias) {
      $record = (object) array(
        'domain_id' => $this->id,
        'alias' => $alias,
      );
      backdrop_write_record('domain_alias', $record);
    }

    return $return;
  }
}

/**
 * Controller class for domains.
 *
 * This extends the EntityDatabaseStorageController class, adding required
 * special handling for domain objects.
 */
class DomainStorageController extends EntityDatabaseStorageController {

  /**
   * Overrides EntityDatabaseStorageController::attachLoad().
   */
  function attachLoad(&$queried_domains, $revision_id = FALSE) {

    // Add any additional aliases from the database.
    $result = db_query('SELECT alias, domain_id FROM {domain_alias} WHERE domain_id IN (:ids)', array(':ids' => array_keys($queried_domains)));
    foreach ($result as $record) {
      $queried_domains[$record->domain_id]->aliases[] = $record->alias;
    }
  }

  public function delete($ids) {
    $entities = $ids ? $this->load($ids) : FALSE;
    if (!$entities) {
      // If no IDs or invalid IDs were passed, do nothing.
      return;
    }

    // Delete the Domain entities first.
    try {
      parent::delete($ids);
    } catch (Exception $e) {
      throw $e;
    }

    backdrop_set_breadcrumb('@TODO: replace with default entity reference widget.');
  }
}
