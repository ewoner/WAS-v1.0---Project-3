{ pkgs }: {
    deps = [
        pkgs.bashInteractive
        pkgs.unixtools.ping.out
        pkgs.telnet.out
        pkgs.man-db
        pkgs.netcat-gnu
        pkgs.vim
    ];
}