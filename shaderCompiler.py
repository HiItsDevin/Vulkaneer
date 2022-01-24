import platform
import os

def compileShaders(glslangValidatorPath = None):
    if not glslangValidatorPath:
        glslangValidatorPath = "glslangValidator"
    if os.path.isdir("./src\\shaders\\"):
        print("Shaders found:")
        for shader in os.listdir("src\\shaders\\"):
            if shader.endswith(".vert") or shader.endswith(".frag"):
                os.system(f"{glslangValidatorPath} -V -Os -o ./src\\shaders\\" + shader[:-5] + ".spv ./src\\shaders\\" + shader)
    else:
        print("Shaders not found, make sure this script is in the root of the project, or that {project_root}\\src\\shaders\\ or {project_root}\\shaders\\ exists.")

if "VULKAN_SDK" in os.environ or "VK_SDK_PATH" in os.environ or os.path.exists("/usr/bin/glslangValidator"):
    print("Vulkan SDK found")
    compileShaders()
else:
    print("Vulkan SDK/glslangValidator not found")
    glslV_Path = input("Enter the full path to your glslangValidator binary location (I.E. `C:\\VulkanSDK\\1.2.198.1\\Bin\\glslandValidator.exe` or `/usr/bin/glslangValidator): ")
    compileShaders(glslV_Path)
