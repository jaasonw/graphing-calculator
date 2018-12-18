# trash ass build script xd
import os
import time

compiler = "g++"
executable = "graphing_calculator.exe"

includes = []
sources = []
link = []
flags = []

includes.append("include")
includes.append("include/rpn")
includes.append("include/engine")
includes.append("[SFML INCLUDE PATH]")

sources.append("src")
sources.append("src/rpn")
sources.append("src/engine")

link.append("sfml-audio")
link.append("sfml-graphics")
link.append("sfml-network")
link.append("sfml-system")
link.append("sfml-window")

flags.append("-std=c++11")
flags.append("-Wall")
flags.append("-Wextra")
flags.append("-g")

# for some reason clang wont compile unless in c++17 mode and with these flags
if compiler == "clang++":
    flags.append("-std=c++17")
    flags.append("-Xclang -flto-visibility-public-std")

flag_str = ""
for f in flags:
    flag_str += f + " "

include_str = ""
for directory in includes:
    include_str += f"-I\"{directory}/\" "

sources_str = ""
for src in sources:
    for _file in os.listdir(src):
        if (not os.path.isdir(f"{src}/{_file} ")):
            sources_str += f"{src}/{_file} "

link_str = ""
for l in link:
    sources_str += f"-l{l} "

try:
    os.remove(executable)
except:
    pass

cmd = f"{compiler} {flag_str} {include_str} -o {executable} main.cpp {sources_str}"
print(cmd)
t1 = time.time()
os.system(cmd)
t2 = time.time()

print("Operation time Elapsed:", f'{t2 - t1:.2f}', "seconds")
