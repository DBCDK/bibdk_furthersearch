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
      'label' => t('Further search'),
      'field types' => array(
        'bibdk_furthersearch_options',
      ),
    )
  );
}

/**
 * Implements hook_field_formatter_view().
 */

function bibdk_furthersearch_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  #dpm($entity, 'entity');
  /*
  foreach ($items as $delta => $item) {
    $link = bibdk_cart_get_link($item['id']);
    $element[$delta]['#markup'] = theme('bibdk_cart_button', array('add_to_cart' => $link));
  }
  */
  return $element;
}
