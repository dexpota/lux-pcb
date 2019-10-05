[clion-integration]: https://docs.platformio.org/en/latest/ide/clion.html
[platform-io]: https://docs.platformio.org/en/latest/quickstart.html
[license]: https://www.gnu.org/licenses/gpl-3.0.en.html
[license-badge]:  https://img.shields.io/badge/License-GPL--3.0-blue.svg?style=for-the-badge

# Sketches

[![License GPL v3][license-badge]][license]

This directory contains the sketches used with the boards.

- [manual-testing](./manual-testing) is used to manually test the functionality
  of the boards by selecting which LED to light up, its color and its
  intensity;

## Requirements

1. Install **CLion** and follow [these instruction][clion-integration] to integrate **PlatformIO**
   into it;
2. Install **PlatformIO** with `pip`;
    ```
    pip install platformio
    ```
3. Install the sketch dependecies by moving to its root directory and using
   this command;
    ```
    pip lib install
    ```

## References

- [PlatformIO][platform-io];
- [Setup PlatformIO with CLion][clion-integration];
