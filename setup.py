import pybind11.setup_helpers, setuptools

extensions = [
    pybind11.setup_helpers.Pybind11Extension(
        name="coord_trans",
        sources=[
            "module.cc",
            "coord_trans.cpp",
        ],
        cxx_std=17
    )
]

setuptools.setup(ext_modules=extensions)
