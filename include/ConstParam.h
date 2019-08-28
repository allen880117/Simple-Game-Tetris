#ifndef CONSTPARAM_H
#define CONSTPARAM_H

namespace cc{
    
    /*
        To avoid multi-definition,
        add "extern" to these "declaration"
        and "instantiate" at "ConstParam.cpp".

        We can't add "const" before these "declaration",
        or it will generate error.

        By default, "const" is internal linkage,
        can't be use by other files.

        Still need more study.
    */
    extern char cPin[];
    extern char cEmpty[];
    extern char cConner[];
    extern char cDash[];
    extern char cSideEdge[];
    extern char cBlocks[];

    extern int scaleWidth;

} // namespace cc

#endif