/* graph.h
 *
 * Copyright (c) 2015, Matthew Levenstein
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the name of Redis nor the names of its contributors may be used
 *      to endorse or promote products derived from this software without
 *      specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include "map.h"

/* for portability */
#define uint64 unsigned long long

typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct vertexContainer VertexContainer;
typedef struct property Property;
typedef struct edge Edge;

typedef unsigned long word_t;

struct graph {
  map_t* vertices;
};

struct vertex {
  word_t idx;
  Edge* edges;
  Property* properties;
};

struct vertexContainer {
  Vertex* vertex;
  VertexContainer* next;
};

struct edge {
  unsigned char* label;
  Vertex* to;
  Vertex* from;
  Edge* next;
};

struct property {
  unsigned char* key;
  unsigned char* val;
  Property* next;
};

Graph* graph_init (uint64);
Vertex* graph_setVertex (Graph*, unsigned char*, Vertex*);
Vertex* graph_getVertex (Graph*, unsigned char*);
Vertex* graph_vertexInit (void);
VertexContainer* graph_getVertices (Graph*, unsigned char*, unsigned char*, unsigned char*);
void graph_removeVertex (Graph*, unsigned char*);
void graph_vertexAddEdge (Vertex*, Vertex*, unsigned char*);
void graph_vertexRemoveEdge (Vertex*, unsigned char*);
void graph_vertexSetProperty (Vertex*, unsigned char*, unsigned char*);
unsigned char* graph_vertexGetProperty (Vertex*, unsigned char*);
void graph_vertexRemoveProperty (Vertex*, unsigned char*);


#endif