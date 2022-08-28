import os
include = ['.']
libs = ['sfml-graphics', 'sfml-system', 'sfml-window']
cxxflags = ['-g', '-Wall' ,'-Wextra' ,'-pedantic' ,'-std=c++17' ,'-O2' ,'-Wshadow' ,'-Wformat=2' ,'-Wfloat-equal' ,'-Wconversion' ,'-Wcast-qual' ,'-Wcast-align' ,'-D_FORTIFY_SOURCE=2' ,'-fsanitize=address' ,'-fsanitize=undefined', '-fno-sanitize-recover', '-fstack-protector']
# cxxflags = ['-D_GLIBCXX_DEBUG', '-g', '-Wall' ,'-Wextra' ,'-pedantic' ,'-std=c++17' ,'-O2' ,'-Wshadow' ,'-Wformat=2' ,'-Wfloat-equal' ,'-Wconversion' ,'-Wcast-qual' ,'-Wcast-align' ]
# cxxflags = ['-g', '-std=c++17', '-O0','-fsanitize=undefined']
cxxflags_turning_off = ['-Wno-overloaded-virtual', '-Wno-float-conversion', '-Wno-implicit-int-float-conversion', '-Wno-sign-conversion', '-Wno-shorten-64-to-32', '-Wno-implicit-float-conversion']
# cxxflags += cxxflags_turning_off
linkflags =['-D_FORTIFY_SOURCE=2' ,'-fsanitize=address' ,'-fsanitize=undefined', '-fno-sanitize-recover', '-fstack-protector']
# linkflags = ['-fsanitize=undefined']
env = Environment(CPPPATH=include, LINKFLAGS = linkflags, LIBS=libs, CXX = 'clang++', CXXCOMSTR = "Compiling $SOURCE", LINKCOMSTR = "Linking $TARGET"  ,CXXFLAGS = cxxflags)
env['ENV']['TERM'] = os.environ['TERM']
env.Decider('MD5-timestamp')
env.Tool('compilation_db')
env.CompilationDatabase()
sources = Glob('*/*.cc') + Glob('*.cc')
env.Program('mario', sources)
