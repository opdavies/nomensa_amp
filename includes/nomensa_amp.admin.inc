<?php

/**
 * @file
 *
 */

/**
 *
 */
function nomensa_amp_admin_settings_form() {
  $defaults = variable_get('nomensa_amp_settings');

  $form['nomensa_amp_settings']['#tree'] = TRUE;

  $form['nomensa_amp_settings']['players'] = array(
    '#title' => t('Players'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );
  
  $players = array(
    'youtube' => 'YouTube',
    'vimeo' => 'Vimeo',
    'jwplayer' => 'jwPlayer',
  );
  
  foreach ($players as $key => $name) {
    $form['nomensa_amp_settings']['players'][$key] = array(
      '#title' => $name,
      '#type' => 'checkbox',
      '#default_value' => $defaults['players'][$key],
    );
  }

  $form = system_settings_form($form);

  return $form;
}
