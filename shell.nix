{
  pkgs ? import <nixpkgs> {}
}: pkgs.mkShell {
  packages = with pkgs; [
    gnumake
    libgcc
    man-pages
  ];
}
