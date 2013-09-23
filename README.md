OptimCSS
========

Based on the module of 'compilerconstruction', master-course at university of applied sciences Osnabrück, germany, a (f)lex and yacc/bison based css source to source compiler was written in plain C, Makefile included. This was a research project, its not recommended to use in production or productive environment.


Authors
=======

Oliver Erxleben (oliver.erxleben@me.com, https://github.com/olivererxleben, Maintainer)

Sergej Hert (sergej.hert@gmail.com, https://github.com/joernoo)

Jörn Voßgröne (jornoo@gmail.com, https://github.com/S3RG3J)

Usage
=====

./path/to/repocode/hausarbeit/app/optimCSS -f /path/to/www/

Parameters:

-f filename

-m minifying 

-s structured

How it Works
============

After input folder was checked for included css files, all css files are merged into one big file. Then a tree of each CSS-Rule will be produced. On this tree, finally, some optimizations will be made and the css file output.css will be written back to css. 

Licence
=======

OptimCSS
Copyright (C) 2013  Oliver Erxleben, Sergej Hert, Jörn Voßgröne

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.