//
//  TNKUIRefreshControlTableViewController.m
//  TNKRefreshControl
//
//  Created by David Beck on 1/13/15.
//  Copyright (c) 2015 David Beck. All rights reserved.
//

#import "TNKUIRefreshControlTableViewController.h"

#import "Example-Swift.h"


@interface TNKUIRefreshControlTableViewController ()
{
    TNKDateSource *_objectSource;
}

@end

@implementation TNKUIRefreshControlTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.refreshControl = [[UIRefreshControl alloc] init];
//    self.refreshControl.attributedTitle = [[NSAttributedString alloc] initWithString:@"Refreshing"];
    [self.refreshControl addTarget:self action:@selector(refresh:) forControlEvents:UIControlEventValueChanged];
    
    _objectSource = [TNKDateSource new];
    _objectSource.objects = @[@"000"];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self refresh:nil];
}


#pragma mark - Actions

- (IBAction)refresh:(id)sender {
    [self.refreshControl beginRefreshing];
	
	[_objectSource loadNewObjectsWithCompletion:^(NSArray *newDates) {
		[self.refreshControl endRefreshing];
		
		[self.tableView reloadData];
	}];
}

- (IBAction)clear:(id)sender {
    _objectSource.objects = @[];
    [self.tableView reloadData];
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _objectSource.objects.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DateCell" forIndexPath:indexPath];
    
    NSObject *item = _objectSource.objects[indexPath.row];
    cell.textLabel.text = item.description;
    
    return cell;
}

@end
