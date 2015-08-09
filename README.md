# ring-catcher
A generic, template C++ class that allows for storing an however complex structure of data at the effort of just a couple rows of code.

Its original intent is to save samples of time series at runtime so as to perform later analysis (post-mortem, performance optimization, debug etc.) without the struggles of little detail management and manually handling loads of data.

The output of this program can be conveniently used in conjunction with another of my projects: csv-cruncher (https://github.com/seatedscribe/csv-cruncher); parsed data is stored in STL container (deque) for easy analisys or automated processing.
