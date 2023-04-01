namespace implies {

class Bool;

namespace detail {

class Impliable {
public:
  constexpr Impliable(bool x) : val(x) {}
  constexpr Bool operator>(Bool other);
  /// This means we're inside a chain of implications, like
  /// `A --> B --> C`
  /// It is parenthesized as `((A--) > (B--)) > C`.
  /// We want to restore the right meaning of that, so we
  /// need to return an `Impliable`!
  constexpr Impliable operator>(Impliable other) {
    return Impliable((!val) || other.val);
  }
private:
  bool val;
};

}

class Bool {
public:
  constexpr Bool(bool x) : val(x) {}
  constexpr operator bool() { return val; }
  constexpr Bool operator!() { return Bool(!val); }
  constexpr Bool operator&&(Bool other) { return Bool(val && other.val); }
  constexpr Bool operator||(Bool other) { return Bool(val || other.val); }
  constexpr Bool operator^(Bool other) { return Bool(val ^ other.val); }

  constexpr detail::Impliable operator--(int) {
    return detail::Impliable(val);
  }

private:
  bool val;
};

namespace detail {
inline constexpr Bool Impliable::operator>(Bool other) {
  return (!val) || other;
}
}

}
