from build_system import environment

env = environment.env(deps = 'clas6 cern root')

env.load_dependency('clas6')
env.load_dependency('cern')
env.load_dependency('root')

env.AppendUnique(CPPPATH = ['.'])

# Temp Use
#env.Append(LIBPATH = ['/volatile/clas12/dmriser/temp/build_recsis/build/lib'])

import glob
#src_list = glob.glob('*.cxx')

#for source in src_list:
#        env.program(source=[source])

env.program('bos2root22',['bos2root22.cxx','Options.cxx','h22Event.cxx'])