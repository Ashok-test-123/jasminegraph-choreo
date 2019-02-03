/**
Copyright 2019 JasminGraph Team
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

#ifndef JASMINEGRAPH_JASMINEGRAPHHASHMAPLOCALSTORE_H
#define JASMINEGRAPH_JASMINEGRAPHHASHMAPLOCALSTORE_H

#include "JasmineGraphLocalStore.h"
#include "../util/dbutil/edgestore_generated.h"
#include <flatbuffers/util.h>

using namespace JasmineGraph::Edgestore;


class JasmineGraphHashMapLocalStore : public JasmineGraphLocalStore {
private:
    std::string VERTEX_STORE_NAME = "acacia.nodestore.db";
    std::string EDGE_STORE_NAME = "acacia.edgestore.db";
    std::string ATTRIBUTE_STORE_NAME = "acacia.attributestore.db";

    int graphId;
    int partitionId;
    std::string instanceDataFolderLocation;
    std::map<long, std::unordered_set<long>> localSubGraphMap;

    long vertexCount;
    long edgeCount;
    int *distributionArray;


    std::string getFileSeparator();

    void toLocalSubGraphMap(const EdgeStore *edgeStoreData);

public:
    JasmineGraphHashMapLocalStore(int graphid, int partitionid);

    JasmineGraphHashMapLocalStore(std::string folderLocation);

    inline bool loadGraph();

    bool storeGraph();

    long getEdgeCount();

    long getVertexCount();

    void addEdge(long startVid, long endVid);

    unordered_set<long> getVertexSet();

    int *getOutDegreeDistribution();

    map<long, long> getOutDegreeDistributionHashMap();

    map<long, unordered_set<long>> getUnderlyingHashMap();

    void initialize();

    void addVertex(string *attributes);
};


#endif //JASMINEGRAPH_JASMINEGRAPHHASHMAPLOCALSTORE_H