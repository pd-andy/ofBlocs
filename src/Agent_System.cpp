#include "Agent_System.h"

//--------------------------------------------------------------
// Constructor -------------------------------------------------
Agent_System::Agent_System() {

}

//--------------------------------------------------------------
// Public Functions --------------------------------------------
int Agent_System::size() {
	return s;
}

//--------------------------------------------------------------
void Agent_System::addAgent() {
	a.push_back(Agent());

	s++;
}

void Agent_System::removeAgent() {
	if (s > 0) {
		a.pop_back();

		s--;
	}
}

void Agent_System::removeAgent(int i) {
	if (s > 0 && i < s) {
		a.erase(a.begin() + i);

		s--;
	}
}
//--------------------------------------------------------------

Agent & Agent_System::getAgent(int i)
{
	return a[i];
}

//--------------------------------------------------------------
void Agent_System::updateAgent(int i) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::updateAgent: Index out of bounds, wrapping to vector size.");
	}

	a[i % s].update();
}

//--------------------------------------------------------------
void Agent_System::resizeAgentGrid(int i, int width, int height) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::resizeAgentGrid: Index out of bounds, wrapping to vector size.");
	}

	a[i % s].resizeGrid(width, height);
}

//--------------------------------------------------------------
void Agent_System::updateAgentGrid(int i, int x, int y, bool b) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::updateAgentGrid: Index out of bounds, wrapping to vector size.");
	}

	a[i % s].updateGrid(x, y, b);
}

void Agent_System::updateAgentGrid(int i, int j, bool b) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::updateAgentGrid: Index out of bounds, wrapping to vector size.");
	}

	a[i % s].updateGrid(j, b);
}

//--------------------------------------------------------------
bool Agent_System::hasAgentCollided(int i) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::hasAgentCollided: Index out of bounds, wrapping to vector size.");
	}
	return a[i % s].hasCollided();
}

//--------------------------------------------------------------
int Agent_System::getAgentX(int i) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::getAgentX: Index out of bounds, wrapping to vector size.");
	}
	return a[i % s].getX();
}

int Agent_System::getAgentY(int i) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::getAgentY: Index out of bounds, wrapping to vector size.");
	}
	return a[i % s].getY();
}

ofPoint Agent_System::getAgentPos(int i) {
	if (i >= s) {
		ofLog(OF_LOG_WARNING, "Agent_System::getAgentPos: Index out of bounds, wrapping to vector size.");
	}
	return a[i % s].getPos();
}