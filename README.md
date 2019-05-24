# ame16
AME16 for C++ with optional python binding

# usage
Add .h and .cpp files into your project and:

```
    double mn = ame16::get_nuclear_mass(12,6); // nuclear mass of 12C in ame unit
    double sp = ame16::Sp(12,6); // 12C Proton Separation Energy 
    double sp = ame16::Sp(12,6,2); // 12C 2-Proton Separation Energy
```

# python bindings
Use cmake to build python module, pybind11 is required.
```
    import pyame
    pyame.Sn(12,6)
    pyame.Sp(12,6,2)         
```
