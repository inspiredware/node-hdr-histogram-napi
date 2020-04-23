{
  "targets": [
    {
      "target_name": "binding",
      "sources": [
        "binding-src/binding.cc",
        "<!@(node -p \"require('fs').readdirSync('./binding-src/binding-util').map(f=>'binding-src/binding-util/'+f).join(' ')\")",
        "<!@(node -p \"require('fs').readdirSync('./binding-src/binding').map(f=>'binding-src/binding/'+f).join(' ')\")",
        "<!@(node -p \"require('fs').readdirSync('./HdrHistogram_c/src').map(f=>'HdrHistogram_c/src/'+f).join(' ')\")"
      ],
      "include_dirs": [
        "binding-src/binding-util",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-exceptions"
      ],
      "xcode_settings": {
        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "10.7"
      },
      "msvs_settings": {
        "VCCLCompilerTool": {
          "ExceptionHandling": 1
        }
      }
    }
  ]
}