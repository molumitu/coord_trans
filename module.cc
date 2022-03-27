#include <pybind11/pybind11.h>
#include "coord_trans.h"

#define BIND_3_REF(func, p1, p2, p3, doc)                    \
    m.def(#func, [](double p1, double p2, double p3) {  \
        using coord_trans_api::func;                    \
        func(p1, p2, p3);                               \
        return pybind11::make_tuple(p1, p2, p3);                   \
    }, doc, pybind11::arg(#p1).noconvert(), pybind11::arg(#p2).noconvert(), pybind11::arg(#p3).noconvert())

#define BIND_2_REF(func, p1, p2, doc)                    \
    m.def(#func, [](double p1, double p2) {  \
        using coord_trans_api::func;                    \
        func(p1, p2);                               \
        return pybind11::make_tuple(p1, p2);                   \
    }, doc, pybind11::arg(#p1).noconvert(), pybind11::arg(#p2).noconvert())

#define BIND_3_REF_3_ARG(func, p1, p2, p3, p4, p5, p6, doc)  \
    m.def(#func, [](double p1, double p2, double p3, double p4, double p5, double p6) {  \
        using coord_trans_api::func;                    \
        func(p1, p2, p3, p4, p5, p6);                               \
        return pybind11::make_tuple(p1, p2, p3);                   \
    }, doc, pybind11::arg(#p1).noconvert(), pybind11::arg(#p2).noconvert(), pybind11::arg(#p3).noconvert(), pybind11::arg(#p4).noconvert(), pybind11::arg(#p5).noconvert(), pybind11::arg(#p6).noconvert())

PYBIND11_MODULE(coord_trans, m) {
    BIND_3_REF(lonlat2global, x, y, z, "lon lat ele -> global x y z");
    BIND_3_REF(global2lonlat, x, y, z, "global x y z -> lon lat ele");
    BIND_3_REF_3_ARG(global2local, x, y, z, refLon, refLat, refAlt, "global x y z -> local x y z ( seu )");
    BIND_3_REF_3_ARG(local2global, x, y, z, refLon, refLat, refAlt, "local x y z ( seu )-> global x y z ");
    BIND_3_REF_3_ARG(lonlat2local, x, y, z, refLon, refLat, refAlt, "lon lat ele -> local x y z");
    BIND_3_REF_3_ARG(local2lonlat, x, y, z, refLon, refLat, refAlt, "local x y z -> lon lat ele");
    BIND_3_REF_3_ARG(global2enu, x, y, z, refLon, refLat, refAlt, "global x y z -> enu x y z");
    BIND_3_REF_3_ARG(enu2global, x, y, z, refLon, refLat, refAlt, "enu x y z -> global x y z ");
    BIND_3_REF_3_ARG(lonlat2enu, x, y, z, refLon, refLat, refAlt, "lon lat ele -> enu x y z ");
    BIND_3_REF_3_ARG(enu2lonlat, x, y, z, refLon, refLat, refAlt, "enu x y z -> lon lat ele");
    BIND_3_REF_3_ARG(seu2enu, enuX, enuY, enuZ, seuX, seuY, seuZ, "seu x y z -> enu x y z");
    BIND_3_REF_3_ARG(enu2seu, enuX, enuY, enuZ, seuX, seuY, seuZ, "enu x y z -> seu x y z");
    BIND_2_REF(lonlat2mercator, x, y, "lon lat -> mercator");
    BIND_2_REF(mercator2lonlat, x, y, "mercator -> lon lat");
}
