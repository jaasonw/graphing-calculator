# trash ass build script xd
import os

try:
    os.remove('a.exe')
except:
    pass

includes = []
includes.append("include")
includes.append("include/engine")
includes.append("[sfml include path]")

sources = []
sources.append("src")
sources.append("src/engine")

link = []
link.append("sfml-audio")
link.append("sfml-graphics")
link.append("sfml-network")
link.append("sfml-system")
link.append("sfml-window")

flags = "-std=c++11 -Ofast -Wall -Wextra -Wfatal-errors -g"

compiler = "g++"

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

cmd = f"{compiler} {flags} {include_str} -o {output} main.cpp {sources_str}"
print(cmd)
os.system(cmd)
