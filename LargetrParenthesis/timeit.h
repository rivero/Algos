#pragma once

struct timeit
{
	
	std::chrono::duration<double> m_dur{};
	std::chrono::steady_clock::time_point m_tp1;
	std::chrono::steady_clock::time_point m_tp2;
	timeit()
	{
		m_tp1 = std::chrono::high_resolution_clock::now();
	}
	~timeit()
	{
		m_tp2 = std::chrono::high_resolution_clock::now();
		m_dur = m_tp2 - m_tp1;
		std::cout << "duration seconds: " << std::fixed << std::setprecision(12) << m_dur.count() << "\n";
	}


};

