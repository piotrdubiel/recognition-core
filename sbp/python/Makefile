default: build test

build: *.cpp *.h
	source venv/bin/activate && python setup.py install

test:
	source venv/bin/activate && nosetests
