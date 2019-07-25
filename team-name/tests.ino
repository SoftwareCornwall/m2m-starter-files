// Unit test matching `this_is_a_bool_function`
test(this_is_a_bool_function) {
  assertTrue(this_is_a_bool_function(false));
  assertFalse(this_is_a_bool_function(true));
}

test(this_is_an_int_function) {
  assertEqual(this_is_an_int_function(10, 25), 35);
}

