#pragma once
#include <queue>
#include <bitset>
#include <optional>
class Keyboard
{
private:
	friend class Window;
public:
	class Event
	{
	public:
		enum class Type
		{
			Press = 0,
			Release,
		};
	private:
		Type _type;
		unsigned char _code;
	public:
		Event(Type type, unsigned char code) noexcept
			:
			_type(type),
			_code(code)
		{}
		bool IsPress() const noexcept
		{
			return _type == Type::Press;
		}
		bool IsRelease() const noexcept
		{
			return _type == Type::Release;
		}
		unsigned char GetCode() const noexcept
		{
			return _code;
		}
	};
public:
	Keyboard() = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard& operator=(const Keyboard&) = delete;
	// key event stuff
	bool KeyIsPressed(unsigned char keycode) const noexcept;
	std::optional<Event> ReadKey() noexcept;
	bool KeyIsEmpty() const noexcept;
	void FlushKey() noexcept;
	// char event stuff
	std::optional<char> ReadChar() noexcept;
	bool CharIsEmpty() const noexcept;
	void FlushChar() noexcept;
	void Flush() noexcept;
	// autorepeat control
	void EnableAutorepeat() noexcept;
	void DisableAutorepeat() noexcept;
	bool AutorepeatIsEnabled() const noexcept;
private:
	void OnKeyPressed(unsigned char keycode) noexcept;
	void OnKeyReleased(unsigned char keycode) noexcept;
	void OnChar(char character) noexcept;
	void ClearState() noexcept;
	template<typename T>
	static void TrimBuffer(std::queue<T> & buffer) noexcept;
private:
	static constexpr unsigned int nKeys = 256u;
	static constexpr unsigned int bufferSize = 16u;
	bool autorepeatEnabled = false;
	std::bitset<nKeys> keystates;
	std::queue<Event> keybuffer;
	std::queue<char> charbuffer;
};

