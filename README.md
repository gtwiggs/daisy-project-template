# Daisy Template

An edition of "blink the LED" as a project template. Uses an oscillator to flash the LED during audio callback. Flashing the LED is trivial functionality, but works as "proof of life" when setting up a new project.

Consider for future revisions a framework to:

- Define a board, i.e., the hardware controls attached to the daisy seed.
- Declare callbacks to process hardware controls.
- Declare parameters used by the project.

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

Review additional project properties for setup and building.

- Declare the parent directory containing libDaisy and DaisySP projects.
```json
"electrosmithFolder": "${workspaceFolder}/../electro-smith",
```
- Define a property unique to Daisy Seed projects:
 ```json
"workspaceKeybindings.daisyseed.enabled": true,
```
- That enables build & flash keyboard shortcuts added to `~/Library/Application Support/Code/User/keybindings.json`:
```json
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

## ReadMe

Edit this file to describe your project :)
