SHELL = /bin/bash
PYTHON_VENV = venv

all: setup
	source $(PYTHON_VENV)/bin/activate && pip install .

run: all
	./$(PYTHON_VENV)/bin/python3.9 demo.py

setup:
	if [ ! -d $(PYTHON_VENV) ]; then python3 -m venv $(PYTHON_VENV); fi;

clean:
	rm -rf $(PYTHON_VENV)
