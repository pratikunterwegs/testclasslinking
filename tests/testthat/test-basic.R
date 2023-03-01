test_that("Getting sequence with class and TBB", {
  expect_identical(
    get_numbers(10),
    seq(0L, 9L, 1L)
  )
})

test_that("Getting sequence with class and no TBB", {
  expect_identical(
    get_numbers(10, multithreaded = FALSE),
    seq(0L, 9L, 1L)
  )
})

test_that("Getting sequence with iteration", {
  expect_identical(
    get_numbers_vec(10),
    seq(0L, 9L, 1L)
  )
})
