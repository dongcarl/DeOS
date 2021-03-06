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

#include "deNode.h"

#ifdef __cplusplus
extern "C" {
#endif

deNode *
newNode(int type)
{   deNode *self = (deNode *) malloc(sizeof(deNode));
    if (self == NULL) return NULL;
    memset(self, 0, sizeof(deNode));
    if (setNodeType(self, 1) < 1)
    {   freeNode(self);
        self = NULL;
    }
    return self;
}

int
freeNode(deNode *self)
{   if (NULL == self) return -1;
    free(self);
    return 0;
}

int
getNodeType(deNode *self)
{   if (NULL == self) return -1;
    return self->type;
}

int
setNodeType(deNode *self, int type)
{   if (1 > type) return 0; /* bad type */
    self->type = type; /* assign type */
    if (self->type == type) /* if type set */
        return self->type; /* return type */
    return -1; /* assign error */
}

#ifdef __cplusplus
}
#endif
