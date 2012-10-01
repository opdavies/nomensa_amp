<?php

/**
 * @file
 * Administration settings for the Nomensa Accessible Media Player module.
 */

/**
 * Form constructor function for the admin settings form.
 *
 * @see nomensa_amp_menu()
 */
function nomensa_amp_admin_settings_form($form_state) {
  $form['players'] = array(
    '#title' => t('Players'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
  );

  $form['players']['nomensa_amp_youtube'] = array(
    '#title' => t('YouTube'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('nomensa_amp_youtube', 0),
  );

  $form['players']['nomensa_amp_vimeo'] = array(
    '#title' => t('Vimeo'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('nomensa_amp_vimeo', 0),
  );

  $form['players']['nomensa_amp_jwplayer'] = array(
    '#title' => t('jwPlayer'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('nomensa_amp_jwplayer', 0),
  );

  $form['advanced'] = array(
    '#title' => t('Advanced settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['advanced']['nomensa_amp_minified'] = array(
    '#title' => t('Use minified CSS and javascript'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('nomensa_amp_minified', 0),
  );

  return system_settings_form($form);
}
