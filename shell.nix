{
  pkgs ? import <nixpkgs> {}
}: pkgs.mkShell {
  packages = with pkgs; [
    gdb
    gnumake
    libgcc
    man-pages
  ];
}
