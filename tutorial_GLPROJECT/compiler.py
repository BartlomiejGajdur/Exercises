import subprocess

file_name = "app"

include_dir = "dependencies/include"
lib_dir = "dependencies/lib"

lib = "-lglfw3 -lglew32s -lopengl32 -lgdi32"

preprocessor = "-DGLEW_STATIC"


def main():
    #compile
    subprocess.call(f"g++ {preprocessor} -c main.cpp -I {include_dir}")

    #link
    subprocess.call(f"g++ {preprocessor} *.o -o {file_name} -L {lib_dir} {lib}")

if __name__ == "__main__":

    main()