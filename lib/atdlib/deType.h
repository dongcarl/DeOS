/* BSD 2-Clause License

Copyright (c) 2013-2016 Andrew T. DeSantis. All rights reserved.
Copyright (c) 2016 DeSantis Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __DETYPE__
#define __DETYPE__

#ifdef __cplusplus
extern "C" {
#endif

#define ENUM_MACRO(T,I) TYPE_##T = I,
#define TYPE_TABLE \
X(1,  ARRAY_CHAR,   "deArray(char) *this"   ) \
X(2,  ARRAY_DOUBLE, "deArray(double) *this" ) \
X(3,  ARRAY_INT,    "deArray(int) *this"    ) \
X(4,  CONTAINER,    "deContainer(int) *this") \
X(5,  NODE,         "deNode *this"          ) \
X(6,  NONE,         "deObject *this"        ) \
X(7,  LIST,         "deList *this"          ) \
X(8,  LIST_NODE,    "deListNode *this"      ) \
X(9,  OBJECT,       "deObject *this"        ) \
X(10, OS,           "deOS *this"            ) \
X(11, SHELL,        "deShell *this"         ) \
X(12, TREE,         "deTree *this"          ) \
X(13, TREE_NODE,    "deTreeNode *this"      )

enum deType {
#define X(I,T,S) ENUM_MACRO(T,I)
TYPE_TABLE
#undef X
} type;

#undef TYPE_TABLE
#undef ENUM_MACRO

#ifdef __cplusplus
}
#endif

#endif /* __DETYPE__ */
