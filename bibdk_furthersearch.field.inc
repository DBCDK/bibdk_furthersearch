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
 * @param String $entity_type
 * @param bibdkWork $entity
 * @param array $field
 * @param array  $instance
 * @param String $langcode
 * @param array $items
 * @param array $display
 * @return array
 */
function bibdk_furthersearch_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $furtherSearches = $entity->getFurtherSearches();

  $themeArray['types'] = isset($furtherSearches['furtherSearchType']) ? $furtherSearches['furtherSearchType'] : array();
  $themeArray['elements'] = isset($furtherSearches['furtherSearchElement']) ? $furtherSearches['furtherSearchElement'] : array();
  $themeArray['fictions'] = isset($furtherSearches['furtherSearchFiction']) ? $furtherSearches['furtherSearchFiction'] : array();

  $element[]['#markup'] = theme('bibdk_furthersearch_tab_content', $themeArray);

  return $element;
}
