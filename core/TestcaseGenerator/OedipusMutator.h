/*
Copyright 2017-2019 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Author(s): Roman Bendt, Thomas Riedmaier, Abian Blome
*/

§§#pragma once
§§#include "FluffiMutator.h"
§§
§§class FluffiServiceDescriptor;
§§class TestcaseDescriptor;
§§class FluffiTestcaseID;
§§class CommInt;
§§class TGWorkerThreadState;
§§class OedipusMutator : public FluffiMutator
§§{
§§public:
	OedipusMutator(FluffiServiceDescriptor serviceDescriptor, std::string testcaseDirectory, CommInt* commInt, TGWorkerThreadState* workerThreadState);
§§	virtual ~OedipusMutator();
	const static int m_numberOfNeededParents{ 2 };
§§
§§	bool isSetupFunctionable();
§§	std::deque<TestcaseDescriptor> batchMutate(unsigned int numToGenerate, const FluffiTestcaseID parentID, const std::string parentPathAndFilename);
§§
§§private:
	static std::string string2hex(const std::string& input);
	std::string encodedDBcredentials{ "" };
§§
	CommInt* m_commInt;
	TGWorkerThreadState* m_workerThreadState;
§§};
