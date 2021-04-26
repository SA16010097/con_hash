# con_hash
cpp consistent hash

c++实现的一致性hash

见code，应用的主要问题在于如何选择key_hash_fun，以提升hash性能。

# To do
多线程环境需加锁。该场景对于内存读多写少，建议加读写锁。考虑使用std::shared_mutex（C++17）或boost::shared_mutex，待实现。
