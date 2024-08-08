#!/usr/bin/perl
use warnings;
use strict;

die "Usage: $0 x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;

# Open the file for writing
open my $fh, '>', 'example_file' or die "Could not open file 'example_file' $!";

# Print the filename as specified
print $fh "${y}456\n";

# Generate the map and write to the file
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print $fh "5";
        } else {
            print $fh "4";
        }
    }
    print $fh "\n";
}

# Close the file handle
close $fh;
