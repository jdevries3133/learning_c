all:
	python3 setup.py build

venv:
	python3 -m venv venv \
		&& source venv/bin/activate \
		&& python3 setup.py build \
		&& pip install . --no-cache-dir \

clean:
	rm -rf build venv
