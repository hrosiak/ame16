/*
 *  Copyright(C) 2017, Andrej Prochazka
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.

 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pybind11/pybind11.h>
#include "ame16.h"

using namespace ame16;
namespace py = pybind11;

PYBIND11_MODULE(pyame, m){
	m.def("get_nuclear_mass",&get_nuclear_mass,"nuclear mass");
	m.def("Sn",&Sn, "Neutron separation energy", py::arg("a"), py::arg("z"), py::arg("n")=1);
	m.def("Sp",&Sp, "Proton separation energy",py::arg("a"), py::arg("z"), py::arg("n")=1);
	m.def("Sa",&Sa, "Alpha separation energy");
	m.def("BA",&BA, "Binding energy per nucleon");
	m.def("S",&S, "Separation energy for (p,n) particle ");
}
