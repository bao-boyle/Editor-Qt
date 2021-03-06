#include "changeparty.h"
#include "ui_changeparty.h"

ChangeParty::ChangeParty(QWidget *parent, RPG::EventCommand &cmd) :
	QDialog(parent),
	ui(new Ui::ChangeParty),
	cmd(cmd)
{
	ui->setupUi(this);

	(cmd.parameters[0] ? ui->op_rem : ui->op_add)->setChecked(true);

	if (cmd.parameters[1] == 0)
	{
		ui->target_specific->setCurrentIndex(cmd.parameters[2]);
		ui->target_box_specific->setChecked(true);
	}
	else
	{
		ui->target_variable->setCurrentIndex(cmd.parameters[2]);
		ui->target_box_variable->setChecked(true);
	}
}

ChangeParty::~ChangeParty()
{
	delete ui;
}

void ChangeParty::on_ChangeParty_accepted()
{
	cmd.parameters[0] = ui->op_rem->isChecked() ? 1 : 0;
	cmd.parameters[1] = ui->target_box_variable->isChecked() ? 1 : 0;
	cmd.parameters[2] = ui->target_box_variable->isChecked() ? ui->target_variable->currentIndex() : ui->target_specific->currentIndex();
}
