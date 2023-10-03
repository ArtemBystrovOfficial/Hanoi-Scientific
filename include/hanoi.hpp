#pragma once
#include "task_queue.hpp"
#include "optimization.hpp"
#include <atomic>
#include <thread>
#include <fstream>

using namespace std::chrono_literals;

namespace hanoi {

template<hanoi_limit N, hanoi_limit M>
class Hanoi {
public:
	//initial
	Hanoi() {};
	void run() {
#ifndef PARALLEL_MODE
		std::cout << std::string(30, '-') << std::endl;
		std::cout << "N: " << int(N) << " M: " << int(M) << std::endl;
		std::cout << std::string(30, '-') << std::endl;
#endif	
		while (true) {
			Frame<N, M> frame = RecursiveQueue<N, M>::Instance().pop();
			//frame.dumpData();
			frame_moves moves(make_basic_moves<N>());
			OptimizationPacket<N, M>::Instance().iterate(&moves, frame);
			if (frame.dumpEnd()
#ifdef PARALLEL_MODE
				|| is_result_promised.load()
#endif	
				) {
				break;
			}
			frame.acceptMoves(&moves);
			while (!frame.isEndIterate())
				RecursiveQueue<N, M>::Instance().push(frame.generateNext());
		}
#ifdef PARALLEL_MODE
		if (!is_result_promised.exchange(true))
#endif
			OptimizationPacket<N, M>::Instance().dumpScoreOptimization();
	}
	private:
#ifdef PARALLEL_MODE
	std::atomic<bool> is_result_promised{ false };
#endif
};

template <int First, int Last, typename Lambda>
inline void static_for(Lambda const& f)
{
	if constexpr (First < Last)
	{
		f(std::integral_constant<int, First>{});
		static_for<First + 1, Last>(f);
	}
}

template<hanoi_limit N, hanoi_limit M>
void singleRun() {
	hanoi::Hanoi<N, M> hanoi;
	auto start = std::chrono::steady_clock::now();
#ifdef PARALLEL_MODE

	std::vector<std::thread> ths(std::thread::hardware_concurrency());
	for (int i = 0; i < std::thread::hardware_concurrency(); ++i)
		ths[i] = std::thread([&]() { hanoi.run(); });
	for (auto& th : ths)
		th.join();
#else
	hanoi.run();
#endif
	auto end = std::chrono::steady_clock::now();
	std::cout << "Time execution: " <<
		std::chrono::duration <double, std::milli>(end - start).count() / 1000 << "s" << std::endl;

}

}