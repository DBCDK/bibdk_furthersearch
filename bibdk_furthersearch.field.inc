<?php

/**
 * Implements hook_field_info().
 */
function bibdk_furthersearch_field_info() {
  return array(
    'bibdk_furthersearch_options' => array(
      'label' => t('Further search'),
      'description' => t('Extracts and displays further search information'),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_furthersearch_default',
      'no_ui' => TRUE,
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 */
function bibdk_furthersearch_field_formatter_info() {
  return array(
    'bibdk_furthersearch_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'bibdk_furthersearch_options',
      ),
    )
  );
}

/**
 * Implements hook_field_load()
 */
function bibdk_furthersearch_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  foreach ($entities as $id => $entity) {
    $items[$id][0] = array(
      'id' => $id,
    );
  }
}

/**
 * Implements hook_field_formatter_view().
 *
 * @param String $entity_type
 * @param bibdkWork $entity
 * @param array $field
 * @param array $instance
 * @param String $langcode
 * @param array $items
 * @param array $display
 * @return array
 */
function bibdk_furthersearch_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $furtherSearchArray = _bibdk_furthersearch_get_further_search($entity);
  $form = bibdk_furthersearch_get_table($furtherSearchArray, $entity->getId());

  #$element[]['#markup'] = theme('bibdk_furthersearch_tab_content', $furtherSearchArray);
  $element[]['#markup'] = drupal_render($form);
  return $element;
}

/**
 * @param bibdkWork $entity
 * @return array
 */
function _bibdk_furthersearch_get_further_search($entity) {
  $furtherSearches = $entity->getFurtherSearches();
  $furtherSearchArray = array();
  if ($furtherSearches) {
    $furtherSearchArray['types'] = isset($furtherSearches['furtherSearchType']) ? $furtherSearches['furtherSearchType'] : array();
    $furtherSearchArray['elements'] = isset($furtherSearches['furtherSearchElement']) ? $furtherSearches['furtherSearchElement'] : array();
    $furtherSearchArray['fictions'] = isset($furtherSearches['furtherSearchFiction']) ? $furtherSearches['furtherSearchFiction'] : array();
  }
  return $furtherSearchArray;
}
