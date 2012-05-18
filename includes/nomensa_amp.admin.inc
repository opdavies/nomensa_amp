<?php

/**
 * @file
 *
 */

/**
 *
 *
 * @see nomensa_amp_menu()
 */
function nomensa_amp_admin_settings_form() {
  $defaults = variable_get('nomensa_amp_settings');

  $form['nomensa_amp_settings']['#tree'] = TRUE;

  $form['nomensa_amp_settings']['players'] = array(
    '#title' => t('Enabled Players'),
    '#type' => 'fieldset',
  );
  
  $players = array(
    'youtube' => 'YouTube',
    'vimeo' => 'Vimeo',
    'jwplayer' => 'jwPlayer',
  );
  
  // Create a checkbox for each player.
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
