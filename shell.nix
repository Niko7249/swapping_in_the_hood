{ pkgs ? import <nixpkgs> {} }:


(pkgs.buildFHSEnv {
  name = "42_fractolz_env";
  targetPkgs = pkgs: (with pkgs; [
    udev
    alsa-lib
    mesa
  ]) ++ (with pkgs.xorg; [
    libX11
    libXcursor
    libXrandr
    libXext
  ]);
  multiPkgs = pkgs: (with pkgs; [
    udev
    alsa-lib
    gcc
    gnumake   # Use 'pkgs.make' for the 'make' package
    x11idle
    libxml2
    libxslt
    cmakeWithGui
    sfml   
    imgui
    mesa
    freeglut
    clang
    freetype
    glew
    libglvnd
    libGL
    nix-index
  ]);
  runScript = "bash";
}).env
