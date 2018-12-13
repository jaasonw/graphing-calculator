
# trash ass build script xd
import os
import time

try:
    os.remove('a.exe')
except:
    pass

includes = []
includes.append("include")
includes.append("include/rpn")
includes.append("include/engine")
includes.append("[SFML INCLUDE PATH]")

sources = []
sources.append("src")
sources.append("src/rpn")
sources.append("src/engine")

link = []
link.append("sfml-audio-d")
link.append("sfml-graphics-d")
link.append("sfml-network-d")
link.append("sfml-system-d")
link.append("sfml-window-d")


compiler = "g++"


flags = []
flags.append("-std=c++11")
flags.append("-Wall")
flags.append("-Wextra")
flags.append("-g")

if compiler == "clang++":
    flags.append("-std=c++17")
    flags.append("-Xclang -flto-visibility-public-std")

flag_str = ""

for f in flags:
    flag_str += f + " "

output = "a.exe"

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

cmd = f"{compiler} {flag_str} {include_str} -o {output} main.cpp {sources_str}"
print(cmd)
t1 = time.time()
os.system(cmd)
t2 = time.time()

print("Operation time Elapsed:", f'{t2 - t1:.2f}', "seconds")
