<?php

/**
 * Implements hook_ding_entity_fields
 **/
function bibdk_furthersearch_ding_entity_fields() {
  $display_full = array(
    'reservation' => array(
      'type' => 'hidden',
    ),
    'full' => array(
      'type' => 'default',
    ),
  );
  return array(
    'bibdk_furthersearch_link' => array(
      'field' => array(
        'locked' => FALSE,
        'storage' => array(
          'type' => 'virtual_field',
        ),
      ),
      'instance' => array(
        'ding_entity_type' => 'bibdkManifestation',
        'label' => t('More like this'),
        'bundle' => 'bibdkManifestation',
        'entity_type' => 'bibdkManifestation',
        'display' => $display_full,
      ),
    ),
  );
}
