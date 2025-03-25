# Daisy Template

My edition of "blink the LED" to use as a project template.

Flashing the LED is trivial functionality, but works as "proof of life" when setting up a new project. I have the intent to elaborate on this basic project to include hardware configuration and an _AudioCallback_ loop.

## Project Setup

After copying this project, customize it to suit your project and environment:

## [Makefile](./Makefile)

- Set your project name: `TARGET = Template`
- Declare your project CPP source files: `CPP_SOURCES = Template.cpp`
- Set the location of `LIBDAISY_DIR` and `DAISYSP_DIR`.  
Many projects add submodules for these repositories. This makes sense if you want to tie a specific version of the libraries to your project, or if your project has many subprojects as it makes the repo more "self-contained",

## [c_cpp_properties.json](./.vscode/c_cpp_properties.json)

- Verify the `compilerPath` setting. You may need to update for your environment.

## [launch.json](./.vscode/launch.json)

- Replace executable `template.elf` with your project name.
```json
"executable": "${workspaceRoot}/build/template.elf",
```

## [settings.json](./.vscode/settings.json)

I've added two custom properties to this file to make project setup easier.

- Declare the parent directory containing libDaisy and DaisySP projects.
```json
"electrosmithFolder": "${workspaceFolder}/../electro-smith",
```
- Define a property unique to Daisy Seed projects:
 ```json
"workspaceKeybindings.daisyseed.enabled": true,
```
- That enables build & flash keyboard shortcuts.
```json
// ~/Library/Application Support/Code/User/keybindings.json
// Place your key bindings in this file to override the defaults
[
  {
    "key": "alt+t",
    "command": "workbench.action.tasks.runTask",
    "args": "build_and_program",
  },
  {
    "key": "shift+alt+t",
    "command": "workbench.action.tasks.runTask",
    "args": "build_and_program_dfu",
  }
]
```

## Replace `README.md`!!
