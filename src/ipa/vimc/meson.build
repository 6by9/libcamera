ipa_name = 'ipa_vimc'

mod = shared_module(ipa_name,
                    'vimc.cpp',
                    name_prefix : '',
                    include_directories : [ipa_includes, libipa_includes],
                    dependencies : libcamera_dep,
                    link_with : libipa,
                    install : true,
                    install_dir : ipa_install_dir)

if ipa_sign_module
    custom_target(ipa_name + '.so.sign',
                  input : mod,
                  output : ipa_name + '.so.sign',
                  command : [ ipa_sign, ipa_priv_key, '@INPUT@', '@OUTPUT@' ],
                  install : false,
                  build_by_default : true)
endif

subdir('data')
