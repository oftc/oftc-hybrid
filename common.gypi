{
  'target_defaults':
  {
    'default_configuration': 'Debug',
    'configurations':
    {
      'Debug':
      {
        'defines': [ 'DEBUG', '_DEBUG' ],
        'cflags': [ '-g', '-O0' ],
        'xcode_settings': {
          'GCC_CW_ASM_SYNTAX': 'NO', # No -fasm-blocks
          'GCC_OPTIMIZATION_LEVEL': 0,
          #'GCC_DEBUGGING_SYMBOLS': 'full',
          'OTHER_CFLAGS': [
            '-g',
          ],
        },
        'msvs_settings':
        {
          'VCCLCompilerTool':
          {
            'RuntimeLibrary': 1, # static debug
            'Optimization': 0, # /Od, no optimization
            'MinimalRebuild': 'false',
            'OmitFramePointers': 'false',
            'BasicRuntimeChecks': 3, # /RTC1
            'DebugInformationFormat': 4,
          },
          'VCLinkerTool':
          {
            'LinkIncremental': 2, #enable incremenetal linking
            'GenerateDebugInformation': 'true',
          },
        },
      },
      'Release':
      {
        'defines': [ 'NDEBUG' ],
        'cflags': [ '-O3' ],
        'xcode_settings': {
          'GCC_CW_ASM_SYNTAX': 'NO',
          'GCC_OPTIMIZATION_LEVEL': 3,
        },
        'msvs_settings':
        {
          'VCCLCompilerTool':
          {
            'RuntimeLibrary': 0, # static release
            'Optimization': 3, # /Ox, full optimization
            'FavorSizeOrSpeed': 1, # /Ot, favour speed over size
            'InlineFunctionExpansion': 2, # /Ob2, inline anything eligible
            'WholeProgramOptimization': 'true', # /GL, whole program optimization, needed for LTCG
            'OmitFramePointers': 'true',
            'EnableFunctionLevelLinking': 'true',
            'EnableIntrinsicFunctions': 'true',
          },
          'VCLibrarianTool':
          {
            'AdditionalOptions':
            [
              '/LTCG', # link time code generation
            ],
          },
          'VCLinkerTool':
          {
            'LinkTimeCodeGeneration': 1, # link-time code generation
            'OptimizeReferences': 2, # /OPT:REF
            'EnableCOMDATFolding': 2, # /OPT:ICF
            'LinkIncremental': 1, # disable incremental linking
          },
        },
      },
    },
    'msvs_settings':
    {
      'VCCLCompilerTool':
      {
        'StringPooling': 'true', # pool string literals
        'DebugInformationFormat': 3, # Generate a PDB
        'WarningLevel': 3,
        'BufferSecurityCheck': 'true',
        'ExceptionHandling': 1, # /EHsc
        'SuppressStartupBanner': 'true',
        'WarnAsError': 'false',
        'AdditionalOptions':
        [
         '/MP', # compile across multiple CPUs
        ],
      },
      'VCLibrarianTool':
      {
      },
      'VCLinkerTool':
      {
        'GenerateDebugInformation': 'true',
        'RandomizedBaseAddress': 2, # enable ASLR
        'DataExecutionPrevention': 2, # enable DEP
        'AllowIsolation': 'true',
        'SuppressStartupBanner': 'true',
        'target_conditions':
        [
          ['_type=="executable"',
          {
            'SubSystem': 1, # console executable
          }],
        ],
      },
    },
  },
}
