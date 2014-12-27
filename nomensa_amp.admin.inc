<?php

/**
 * @file
 *
 */

/**
 * Form constructor for the admin settings form.
 *
 * @see nomensa_amp_menu()
 */
function nomensa_amp_admin_settings_form($form, $form_state) {
  $form['nomensa_amp_settings']['#tree'] = TRUE;

  $form['nomensa_amp_settings']['players'] = array(
    '#title' => t('Enabled Players'),
    '#type' => 'fieldset',
  );

  $available_players = array(
    'youtube' => 'YouTube',
    'vimeo' => 'Vimeo',
    'jwplayer' => 'jwPlayer',
  );

  // Load the default settings.
  $default_settings = variable_get('nomensa_amp_settings');

  // Create a checkbox for each player.
  foreach ($available_players as $player_machine_name => $player_name) {
    $form['nomensa_amp_settings']['players'][$player_machine_name] = array(
      '#title' => $player_name,
      '#type' => 'checkbox',
      '#default_value' => isset($default_settings['players'][$player_machine_name]) ? $default_settings['players'][$player_machine_name] : 0,
    );
  }

  // Advanced settings.
  $form['nomensa_amp_settings']['advanced'] = array(
    '#title' => t('Advanced settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['nomensa_amp_settings']['advanced']['minimised'] = array(
    '#title' => t('Use minified CSS and javascript'),
    '#type' => 'checkbox',
    '#default_value' => isset($default_settings['advanced']['minimised']) ? $default_settings['advanced']['minimised'] : 1,
  );

  return system_settings_form($form);
}
