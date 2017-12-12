#ifndef SINGELTON_HPP
#define SINGELTON_HPP

template <class T>
class TSingelton
{
	protected:

		static T *m_pSingelton;

	public:

		virtual ~TSingelton()
		{

		}

		inline static T* Get()
		{
			if (!m_pSingelton)
				m_pSingelton = new T;

			return(m_pSingelton);
		}

		static void Del()
		{
			delete (m_pSingelton);
			m_pSingelton = NULL;

		}

};


template <class T>
T* TSingelton<T>::m_pSingelton = 0;


#endif